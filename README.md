# ircmatch

This is a python extension which provides string comparison and matching functions from Atheme.
They are hand-optimized for high performance when matching IRC hostmasks.

## Usage

```python
import ircmatch

print ircmatch.match(0, 'kaniini!*@*', 'kaniini!~kaniini@localhost')
```

See also `help(ircmatch)` and `example.py` in this source distribution.
