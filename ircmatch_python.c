/*
 * Copyright (c) 2014 William Pitcock <nenolod@dereferenced.org>.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <Python.h>
#include "ircmatch.h"

static PyObject *
ircmatch_collapse (PyObject * self, PyObject * args)
{
	char * pattern, * copy, * result;
	PyObject * ret;

	if (! PyArg_ParseTuple (args, "s", & pattern))
		return NULL;

	copy = strdup (pattern);
	result = collapse (copy);
	ret = Py_BuildValue ("s", result);
	free(result);

	return ret;
}

static PyObject *
ircmatch_match (PyObject * self, PyObject * args)
{
	char * s1, * s2;
	int match_mapping, result;

	if (! PyArg_ParseTuple (args, "iss", & match_mapping, & s1, & s2))
		return NULL;

	result = !match (match_mapping, s1, s2);
	return Py_BuildValue ("O", result ? Py_True : Py_False);
}

static PyObject *
ircmatch_irccasecmp (PyObject * self, PyObject * args)
{
	char * s1, * s2;
	int match_mapping, result;

	if (! PyArg_ParseTuple (args, "iss", & match_mapping, & s1, & s2))
		return NULL;

	result = irccasecmp (match_mapping, s1, s2);
	return Py_BuildValue ("i", result);
}

static PyObject *
ircmatch_ircncasecmp (PyObject * self, PyObject * args)
{
	char * s1, * s2;
	int match_mapping, result, len;

	if (! PyArg_ParseTuple (args, "issi", & match_mapping, & s1, & s2, & len))
		return NULL;

	result = ircncasecmp (match_mapping, s1, s2, len);
	return Py_BuildValue ("i", result);
}

static PyMethodDef ircmatch_methods[] = {
	{ "collapse", ircmatch_collapse, METH_VARARGS,
	  "Collapse a mask to the simplest possible equivilant representation. Arguments are:\n"
          "   mask: the mask to collapse." },
	{ "match", ircmatch_match, METH_VARARGS,
	  "Matches a mask against a target.  Arguments are:\n"
	  "   match_mapping: 0 means rfc1459, 1 means ascii.\n"
	  "   mask: the mask to match against\n"
	  "   target: the target to match the mask against" },
	{ "irccasecmp", ircmatch_irccasecmp, METH_VARARGS,
	  "Performs a lexographical string comparison against two strings.  Arguments are:\n"
	  "   match_mapping: 0 means rfc1459, 1 means ascii.\n"
	  "   s1: first string\n"
	  "   s2: second string" },
	{ "ircncasecmp", ircmatch_ircncasecmp, METH_VARARGS,
	  "Performs a lexographical string comparison against two strings up to a maximum specified length.\n"
	  "Arguments are:\n"
	  "   match_mapping: 0 means rfc1459, 1 means ascii.\n"
	  "   s1: first string\n"
	  "   s2: second string\n"
	  "   len: length" },
};

#if PY_MAJOR_VERSION >= 3

static struct PyModuleDef ircmatch_moduledef = {
	PyModuleDef_HEAD_INIT,
	"ircmatch",
	NULL,
	0,
	ircmatch_methods,
	NULL,
	NULL,
	NULL,
	NULL
};

PyObject *
PyInit_ircmatch (void)
{
	return PyModule_Create (& ircmatch_moduledef);
}

#else

PyMODINIT_FUNC
initircmatch (void)
{
	Py_InitModule ("ircmatch", ircmatch_methods);
}

#endif
