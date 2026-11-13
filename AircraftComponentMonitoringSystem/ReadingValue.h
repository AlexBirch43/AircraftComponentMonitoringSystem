#pragma once
#include <string>
#include <variant>

//UML Class Diagram: <<datatype>> ReadingValue

using ReadingValue = std::variant<double, std::string>;   //reading is either a numeric value (double) or a non-numeric state (string)