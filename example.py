from __future__ import print_function

import ircmatch

mask = '*rabbit**!*rabbits@**rabb*.it'

print('mask: ' + mask)
print('collapse(): ' + ircmatch.collapse(mask))
print('match(0, "{0}", "{1}"): {2}'.format(mask, 'rabbit!~rabbits@localhost.rabb.it', ircmatch.match(0, mask, 'rabbit!~rabbits@localhost.rabb.it')))
print('match(0, "{0}", "{1}"): {2}'.format(mask, 'rabit!~rabbits@localhost.rabb.it', ircmatch.match(0, mask, 'rabit!~rabbits@localhost.rabb.it')))

print('irccasecmp(0, "{0}", "{1}"): {2}'.format('apple', 'appel', ircmatch.irccasecmp(0, 'apple', 'appel')))
print('irccasecmp(0, "{0}", "{1}"): {2}'.format('apple', 'apple', ircmatch.irccasecmp(0, 'apple', 'apple')))
print('irccasecmp(0, "{0}", "{1}"): {2}'.format('appel', 'apple', ircmatch.irccasecmp(0, 'appel', 'apple')))

print('ircncasecmp(0, "{0}", "{1}", 4): {2}'.format('apple', 'appel', ircmatch.ircncasecmp(0, 'apple', 'appel', 4)))
print('ircncasecmp(0, "{0}", "{1}", 4): {2}'.format('apple', 'apple', ircmatch.ircncasecmp(0, 'apple', 'apple', 4)))
print('ircncasecmp(0, "{0}", "{1}", 4): {2}'.format('appel', 'apple', ircmatch.ircncasecmp(0, 'appel', 'apple', 4)))

print('ircncasecmp(0, "{0}", "{1}", 3): {2}'.format('apple', 'appel', ircmatch.ircncasecmp(0, 'apple', 'appel', 3)))
print('ircncasecmp(0, "{0}", "{1}", 3): {2}'.format('apple', 'apple', ircmatch.ircncasecmp(0, 'apple', 'apple', 3)))
print('ircncasecmp(0, "{0}", "{1}", 3): {2}'.format('appel', 'apple', ircmatch.ircncasecmp(0, 'appel', 'apple', 3)))
