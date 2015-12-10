/* Copyright 2015 Joshua Tacoma
 *
 * This file is part of Madlib.
 *
 * Madlib is free software: you can redistribute it and/or modify it under the
 * terms of the Affero GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * Madlib is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the Affero GNU General Public License for more
 * details.
 *
 * You should have received a copy of the Affero GNU General Public License
 * along with Madlib.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>

#include "madlib.h"

#include "template_impl.h"

void
madlib_template_free
    ( struct madlib_template * t
    )
{
    free (t->buffer);
    free (t);
}
