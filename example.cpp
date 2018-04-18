/*#include "include/pybind11/pybind11.h"
#include <iostream>
#include <string>
#include <string.h>*/
#include "example.h"
using namespace std;
int add(int i, int j) {
    return i + j;
}
int subtract(int i, int j) {
    return i - j;
}
struct Pet {
    Pet(const string &name) : name(name) {}
    void setName(const string &name_) {name = name_;}
    const string &getName() const {return name;}
    string name;
};

namespace py = pybind11;
void print_dict(py::dict dict){
    for(auto item:dict){
        cout << "key=" << string(py::str(item.first)) << ", "
        << "value="<<string(py::str(item.second))<<std::endl;
    }
}
int binarySearch(char *word[], int size, string value)
{
    int first = 0,
    last = size - 1,
    middle,
    position = -1;
    bool found = false;
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (word[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (word[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}
void sortArray(char *string[], const int size)
{
    int pass, i;
    char *temp;
    
    for (pass=0; pass < size - 1; pass++)
    {
        for (i=0; i<size - 1; i++)
        {
            if (strcmp(string[i], string[i+1]) > 0)
            {
                temp = string[i];
                string[i] = string[i+1];
                string[i+1] = temp;
            }
        }
    }
}
bool pageInList(std::string page_name,py::list list) {
   // sortArray(py::str(list))
    for(auto item:list) {
        if(page_name.find(py::str(item)) != string::npos) {
            return true;
        }
    }
    return false;
}
bool equal_case_insensitive(const string& s1, const string& s2)
{
    return(0 == strcasecmp(s1.c_str(), s2.c_str()));
}
string template_figure_type(string temp) {
    if(equal_case_insensitive(temp,"infobox album"))
        return "infobox album";
    else if(equal_case_insensitive(temp,"album infobox"))
        return "album infobox";
    else if(equal_case_insensitive(temp,"album infobox soundtrack"))
        return "album infobox soundtrack";
    else if(equal_case_insensitive(temp,"dvd infobox"))
        return "dvd infobox";
    else if(equal_case_insensitive(temp,"infobox dvd"))
        return "infobox dvd";
    else if(equal_case_insensitive(temp,"infobox ep"))
        return "infobox ep";
    else if(equal_case_insensitive(temp,"extra chronology"))
        return "extra chronology";
    else if(equal_case_insensitive(temp,"extra album cover"))
        return "extra album cover";
    else if(equal_case_insensitive(temp,"extra track listing"))
        return "extra track listing";
    else if(equal_case_insensitive(temp,"extra tracklisting"))
        return "extra tracklisting";
    else
        return "";
}

py::str process(string text){
    py::object mwparser = py::module::import("mwparserfromhell");
    py::object code = mwparser.attr("parse")(py::str(text));
    py::object filtered = code.attr("filter_templates")();
    
    //py::list list;  // list to append to
   // bool bContent_changed = false;
   // py::print(py::str(list));
    for(auto temp : filtered) {
        //auto type = template_figure_type(temp.attr("name"));
        auto type = template_figure_type(py::str(temp.attr("name")));
       // py::print("G ");
        //py::print(type);
     //   auto type = "";
        if(type != ""){
           /* try {
                temp.attr("remove")("link");
                //bContent_changed = true;
            }
            catch(std::domain_error) {
                py::print("In catch");
                continue;
            }
            bContent_changed = true;*/
            //PyObject *f = temp.attr("has")("link");
            py::object bHasLink = temp.attr("has")("link");
            //if(f == Py_True){
            if(py::str(bHasLink).is(py::str(Py_True))){
                py::print("D");
                temp.attr("remove")("link");
                bContent_changed = true;
            }
            //try {
                //list.append(type);
                //return list;
                //py::print(py::str(type));
                
                /*py::object f = temp.attr("has")("link");
                py::print(py::str(f));
                //PyObject *t = Py_True;
               // int tr = PyObject_IsTrue(f);
                
               // if(py::str(f) == py::str("False")) {
               // if(py::str(f).is(py::str("True"))) {
                //if(temp.attr("has")("link")) {
                //if(py::str(f) == py::str("True")){
                if(0){
                //if(py::str(f) == "True"){
                    temp.attr("remove")("link");
                    bContent_changed = true;
          //          list.append(temp);
                }
                else {
                    py::print("NO");
                }
            } catch (std::domain_error) {
                throw std::domain_error("");
            }*/
        }
       // list.append(temp);
    //    py::print(py::str(temp));
    }
    //py::print(py::str(list));
    return py::str(code);
}
bool getContentChanged(){
    return bContent_changed;
}
/*bool bots_allowed(string text) {
    py::object mwparser = py::module::import("mwparserfromhell");
    py::object code = mwparser.attr("parse")(py::str(text));
    py::object filtered = code.attr("filter_templates")();
    for(page:filtered) {
        if((page.attr("name").attr("matches")("nobots") == Py_true || page.attr("name").attr("matches")("Wikipedia:Exclusion compliant") == Py_True) && (page.attr("has")("allow") == Py_True && )) {
            
        }
    }
}*/
bool call_home(py::object site,string user_name){
    //py::print(py::str(site));
    py::object page = site.attr("Pages").attr("__getitem__")("User:" + user_name + "/status");
  //  auto text = page.attr("text")();
    //py::print(py::str(text));
    if(string(py::str( page.attr("text")() )).find("true") != string::npos)
        return true;
    return false;
}



PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
    m.def("sub",&subtract, "A function which subtracts dumbass");
    m.def("print_dict",&print_dict);
    m.def("inlist",&pageInList);
    m.def("template_figure_type",&template_figure_type);
    m.def("process",&process);
    m.def("getContentChanged",&getContentChanged);
    m.def("call_home",&call_home);
    py::class_<Pet>(m, "Pet")
    .def(py::init<const std::string &>())
    .def("setName", &Pet::setName)
    .def("getName", &Pet::getName);
}
