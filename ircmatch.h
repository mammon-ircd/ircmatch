#ifndef IRCMATCH_H
#define IRCMATCH_H

enum match_type {
	MATCH_RFC1459,
	MATCH_ASCII
};

extern const unsigned int charattrs[];

#define BadPtr(x) (!(x) || (*(x) == '\0'))

#define IsAlpha(c)      (charattrs[(unsigned char) (c)] & C_ALPHA)
#define IsDigit(c)      (charattrs[(unsigned char) (c)] & C_DIGIT)
#define IsNickChar(c)   (charattrs[(unsigned char) (c)] & C_NICK)
#define IsUserChar(c)   (charattrs[(unsigned char) (c)] & C_USER)
#define IsAlphaNum(c)   (IsAlpha((c)) || IsDigit((c)))
#define IsNon(c)        (!IsAlphaNum((c)))

extern int ToLower(enum match_type, int);
extern int ToUpper(enum match_type, int);

extern int irccasecmp(enum match_type, const char *, const char *);
extern int ircncasecmp(enum match_type, const char *, const char *, size_t);

extern int match(enum match_type, const char *, const char *);
extern char *collapse(char *);

#endif
