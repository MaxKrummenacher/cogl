/*
 * gerror.c: Error support.
 *
 * Author:
 *   Miguel de Icaza (miguel@novell.com)
 *
 * (C) 2006 Novell, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <config.h>

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <glib.h>

GError *
g_error_new (GQuark domain, gint code, const char *format, ...)
{
	va_list args;
	GError *err = g_new (GError, 1);
	
	err->domain = domain;
	err->code = code;

	va_start (args, format);
	if (vasprintf (&err->message, format, args) == -1)
		err->message = g_strdup_printf ("internal: invalid format string %s", format); 
	va_end (args);

	return err;
}

GError *
g_error_new_valist (GQuark domain, gint code, const char *format, va_list ap)
{
	GError *err = g_new (GError, 1);
	
	err->domain = domain;
	err->code = code;

        err->message = g_strdup_vprintf (format, ap);

	return err;
}

void
g_clear_error (GError **error)
{
	if (error && *error) {
		g_error_free (*error);
		*error = NULL;
	}
}

void
g_error_free (GError *error)
{
	g_return_if_fail (error != NULL);
	
	g_free (error->message);
	g_free (error);
}

void
g_set_error (GError **err, GQuark domain, gint code, const gchar *format, ...)
{
	va_list args;

	if (err) {
		va_start (args, format);
		*err = g_error_new_valist (domain, code, format, args);
		va_end (args);
	}
}

void
g_propagate_error (GError **dest, GError *src)
{
	if (dest == NULL) {
		if (src)
			g_error_free (src);
	} else {
		*dest = src;
	}
}

GError *
g_error_copy (const GError *error)
{
	GError *copy = g_new (GError, 1);
        copy->domain = error->domain;
        copy->code = error->code;
        copy->message = g_strdup (error->message);
        return copy;
}

gboolean
g_error_matches (const GError *error, GQuark domain, gint code)
{
  if (error)
    {
      if (error->domain == domain && error->code == code)
        return TRUE;
      return FALSE;
    }
  else
    return FALSE;
}
