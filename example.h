#include "pybind/include/pybind11/pybind11.h"
#include <iostream>
#include <string>
#include <string.h>

#define CAT_MODULE_STRING_ERRORS "[[Category:Music infoboxes with Module:String errors{{!}}C]]"
#define BOT_USER "DeprecatedFixerBot"

namespace py = pybind11;

namespace Helpers {
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
/**
 * Check if the killswitch has been set to false or not.
 * @return True if it is okay to edit, false if the kill switch has been set to false
 */
bool call_home(py::object site,string user_name);

bool revert(string page_name,py::object site);
