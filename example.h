/**
 Copyright (C) 2018 Kyle Wilson <majorjohn1@mail.com>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 of the Software, and to permit persons to whom the Software is furnished to do
 so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */
#include "pybind/include/pybind11/pybind11.h"
#include <iostream>
#include <string>
#include <string.h>

#define CAT_MODULE_STRING_ERRORS "[[Category:Music infoboxes with Module:String errors{{!}}C]]"
#define BOT_USER "DeprecatedFixerBot"

/**
 * See example.cpp for comments.
 */

namespace py = pybind11;

namespace Helpers {
    /**
     * @brief Reverses a python list
     * @param list List to revert
     * @return void
     */
    const void reverseList(py::list list) {
        list.attr("reverse")();
    }
};

using namespace std;
int subtract(int i, int j);
void print_dict(py::dict dict);
bool pageInList(std::string page_name,py::list list);
string template_figure_type(string temp);
py::str process(string text);
bool bContent_changed = false;
bool getContentChanged();

bool call_home(py::object site,string user_name);

bool revert(string page_name,py::object site);
