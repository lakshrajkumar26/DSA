# RBAC & Workflow — Army Archive System
**Status:** Updated 2026-05-27

---

## 1. Role Hierarchy (11 levels)

| Rank | Role | Tier | Authority |
|------|------|------|-----------|
| 1 | `super_admin` | Admin | Full access everywhere; no scope limit |
| 2 | `hq_admin` | Admin | Full access within assigned HQ |
| 3 | `unit_admin` | Admin | Full access within assigned Unit |
| 4 | `branch_admin` | Admin | Full access within assigned Branch *(new)* |
| 5 | `sub_branch_admin` | Admin | Full access within assigned SubBranch *(new)* |
| 6 | `officer` | Operational | Senior-most operational role; self-approves; approves all below |
| 7 | `jco` | Operational | Junior Commissioned Officer; needs officer/admin approval *(new)* |
| 8 | `clerk` | Operational | Clerical staff; needs officer/admin approval (simplified — no senior/junior) |
| 9 | `nco` | Operational | Non-Commissioned Officer; needs officer/admin approval *(new)* |
| 10 | `or` | Viewer | Other Ranks; view + AI chat only *(new)* |
| 11 | `trainee` | Viewer | Trainee; view + AI chat only |

> **Lower rank number = higher authority.** A `hq_admin` (rank 2) can manage anyone with rank 3–11 within their HQ.

---

## 2. What Each Tier Can Do

### Admin Tier (ranks 1–5)
| Action | super_admin | hq_admin | unit_admin | branch_admin | sub_branch_admin |
|--------|:-----------:|:--------:|:----------:|:------------:|:----------------:|
| Upload documents | ✓ | ✓ | ✓ | ✓ | ✓ |
| Auto-approve own uploads | ✓ | ✓ | ✓ | ✓ | ✓ |
| Approve JCO/Clerk/NCO uploads | ✓ (all) | ✓ (HQ scope) | ✓ (Unit scope) | ✓ (Branch scope) | ✓ (SubBranch scope) |
| Delete documents (direct) | ✓ | ✓ | ✓ | ✓ | ✓ |
| Create / manage users | ✓ | ✓ (HQ) | ✓ (Unit) | ✓ (Branch) | ✓ (SubBranch) |
| Change role/rank of users | ✓ (all below) | ✓ (rank 3–11 in HQ) | ✓ (rank 4–11 in Unit) | ✓ (rank 5–11 in Branch) | ✓ (rank 6–11 in SubBranch) |
| Set document visibility | ✓ | ✓ (HQ) | ✓ (Unit) | ✓ (Branch) | ✓ (Branch) |
| View audit logs (scoped) | ✓ | ✓ | ✓ | ✓ | ✓ |

### Operational Tier (ranks 6–9)
| Action | officer | jco | clerk | nco |
|--------|:-------:|:---:|:-----:|:---:|
| Upload documents | ✓ (auto-approved) | ✓ (needs approval) | ✓ (needs approval) | ✓ (needs approval) |
| Approve JCO/Clerk/NCO uploads | ✓ (same branch) | ✗ | ✗ | ✗ |
| Delete documents | ✓ (direct, same branch) | Request only (own uploads) | Request only (own uploads) | Request only (own uploads) |
| Manage users or access control | ✗ | ✗ | ✗ | ✗ |
| View approved documents (branch scope) | ✓ | ✓ | ✓ (task_category filtered) | ✓ |

### Viewer Tier (ranks 10–11)
| Action | or | trainee |
|--------|:--:|:-------:|
| Upload documents | ✗ | ✗ |
| View approved documents (branch scope) | ✓ | ✓ |
| AI Chat / Q&A | ✓ | ✓ |
| Any write operation | ✗ | ✗ |

---

## 3. Document Upload & Approval Workflow

```
User uploads document
        │
        ▼
Is uploader an Admin or Officer?
        │
  YES ──┤──> Auto-approved → OCR/indexing starts immediately
        │
  NO ───┤──> status = "uploaded" (pending approval)
        │    Document stored in MinIO but NOT processed
        │
        ▼
Senior reviews (Officer in same branch, OR any Admin in scope):
        │
   APPROVE ──> status = "approved" → OCR starts → status = "indexed"
        │      Approval stamped with approver's e-signature (if uploaded)
        │      If no e-signature: "Approved by [Name] [Army No.]"
        │
   REJECT ───> status = "rejected" + rejection_reason + rejected_by
        │      Uploader notified; document stays but is not processed
        │
   NO ACTION ─> status stays "uploaded" (pending)
                Any Admin above officer level can step in to approve
```

### Approval Escalation
If an officer has not acted, **any admin at or above** (branch_admin → unit_admin → hq_admin → super_admin) can approve or reject, ensuring no document is indefinitely blocked.

### Delete Workflow
```
JCO / Clerk / NCO requests delete
        │
        ▼
  status = "delete_requested"
        │
        ▼
Officer or Admin approves delete
        │
        ▼
  File moved to MinIO "deleted/" prefix
  Elasticsearch chunks removed
  status = "deleted"
```

---

## 4. Document Visibility (min_visible_rank)

Set per-document. A user can see a document only if `user.rank_level ≤ document.min_visible_rank`.

| Value | Minimum required role |
|-------|-----------------------|
| 1 | Super Admin only |
| 2 | HQ Admin+ |
| 3 | Unit Admin+ |
| 4 | Branch Admin+ |
| 5 | SubBranch Admin+ |
| 6 | Officer+ |
| 7 | JCO+ |
| 8 | Clerk+ |
| 9 | NCO+ |
| 10 | OR+ |
| 11 | Everyone (Trainee+) |

> Admins can only **lower** visibility to their own rank or below (cannot grant access above their own level).

---

## 5. E-Signature

- Each user can upload a PNG/JPG signature image stored in MinIO under `esignatures/`.
- When a document is approved:
  - **If approver has e-signature** → signature is referenced in approval metadata.
  - **If no e-signature** → approval shows `"Approved by [Name] · [Army No.] · [DateTime]"`.
- Viewable on the user's profile page (`/profile/{id}`).
- Upload restricted to self or any admin above the user.

---

## 6. Scope Rules (Strict)

An admin can **only** manage users and documents within their assigned organisational scope:

| Admin Role | Scope |
|------------|-------|
| super_admin | Entire system — no restrictions |
| hq_admin | All users/docs where `hq_id` matches |
| unit_admin | All users/docs where `unit_id` matches |
| branch_admin | All users/docs where `branch_id` matches |
| sub_branch_admin | All users/docs where `branch_id` + `sub_branch_id` match |

**Cannot modify**: Any user at the same or higher rank, or outside their scope.
**Cannot promote**: Anyone above the acting admin's own rank_level.

---

## 7. Audit Logging

Every action is logged in the `audit_logs` table with:

| Field | Value |
|-------|-------|
| `action` | String tag e.g. `CREATE_USER`, `APPROVE_DOCUMENT`, `DELETE_DOCUMENT` |
| `user_id` | Who performed the action |
| `role` | Their role at time of action |
| `target_id` | Document ID or User ID affected |
| `target_type` | `"document"` or `"user"` or `"system"` |
| `status` | `SUCCESS` or `FAILED` |
| `message` | Error detail on failure |
| `extra` | JSON of request parameters (passwords redacted) |
| `timestamp` | UTC datetime |

Admins can view scoped audit logs via `/users/{id}/audit` and in the Logs page. SuperAdmin sees all.

---

## 8. Profile Page (`/profile/{id}`)

Each user has a profile showing:
- Name, army number, role, rank, designation, scope (HQ/Unit/Branch)
- E-signature upload/replace
- Activity log (last 200 actions, visible to self + admins above)
- Edit button for self (name, designation, password) and admins

---

## 9. Changes from Previous Version

| Before | After |
|--------|-------|
| 6 roles (super_admin, hq_admin, unit_admin, officer, clerk, trainee) | 11 roles — added branch_admin, sub_branch_admin, jco, nco, or |
| clerk had "senior"/"junior" subtypes | clerk is unified — no subtypes |
| Only officer/senior_clerk auto-approved | Any admin tier + officer auto-approves |
| Only officer/unit_admin/hq_admin could approve | All admin tiers + officer can approve (within scope) |
| rank_level capped at 6 in UI | rank_level 1–11 throughout |
| No e-signature | E-signature supported per user |
| No profile page | `/profile/{id}` page with activity log |
| Hierarchy page: flat list | Hierarchy page: visual connecting tree + role chart |
| Access page: basic inline edit | Access page: scoped controls, strict rank enforcement, doc visibility tab |

---

## 10. Pending / Future

- [ ] SubBranch as a DB entity (currently sub_branch_id is an integer reference only)
- [ ] SMS/email notification on pending approvals
- [ ] Document co-approval (requires 2 approvers)
- [ ] Approval reason field (remark) when approving/rejecting
- [ ] Time-limited access tokens for OR/Trainee
