# Clearing the n vs n-1 Confusion

This is the difference between **Cardinality** (How many?) and **Ordinality** (Which position?).

## Golden Tip

**Stick to `i < n` for loops. Use n-1 only inside formulas.**
## The Two Rules

### Rule 1: COUNTING (How many?) → Use **n**
- **Context:** Loop limits, lengths, total heights / widths.
- **Example:** "I want to print 5 stars." → Loop `i < n`
- **Why:** A loop from 0 to n-1 runs exactly n times.

### Rule 2: LOCATING (Where am I?) → Use **n-1 (size)**
- **Context:** Boundaries, specific indices, formulas.
- **Example:** "Print a wall at the very end." → Check `i == n - 1`
- **Why:** In 0-based indexing, the last item's location is always Total - 1.

## Loop Condition Equivalence

These two are identical:
- **`i < n`** (Standard): Run n times, indices 0 to n-1
- **`i <= n - 1`** (Inclusive): Same result, different notation

## Quick Reference

| Need | Use | Code |
|------|-----|------|
| Print n rows | n | `for (i = 0; i < n; i++)` |
| Check last row | n-1 | `if (i == n - 1)` |
| Middle position | n-1 | `(n - 1) / 2` |
| Row formula | n-1 | `2*n - 1 - i` |
