#include <iostream>
#include <string>
#include <vector>

#include "third_party/optional_json.h"

struct SimpleStruct {
    bool bool_;
    int int_;
    double double_;
    std::string string_;
    std::unique_ptr<bool> optional_;
};

struct NestedStruct {
    SimpleStruct nested_;
    std::vector<SimpleStruct> vector_;
};

void to_json(nlohmann::json& j, const SimpleStruct& value) {
    j["_bool"] = value.bool_;
    j["_int"] = value.int_;
    j["_double"] = value.double_;
    j["_string"] = value.string_;
    j["_optional"] = value.optional_;
}

void from_json(const nlohmann::json& j, SimpleStruct& value) {
    j.at("_bool").get_to(value.bool_);
    j.at("_int").get_to(value.int_);
    j.at("_double").get_to(value.double_);
    j.at("_string").get_to(value.string_);
    if (j.find("_optional") != j.cend()) {
        j.at("_optional").get_to(value.optional_);
    }
}

void to_json(nlohmann::json& j, const NestedStruct& value) {
    j["_nested"] = value.nested_;
    j["_vector"] = value.vector_;
}

void from_json(const nlohmann::json& j, NestedStruct& value) {
    j.at("_nested").get_to(value.nested_);
    j.at("_vector").get_to(value.vector_);
}

int main() {
    using nlohmann::json;
    std::cout << json(json::parse("{"
                                  "  \"_nested\": {"
                                  "    \"_bool\": false,"
                                  "    \"_int\": 0,"
                                  "    \"_double\": 0,"
                                  "    \"_string\": \"foo\""
                                  "  },"
                                  "  \"_vector\": [{"
                                  "    \"_bool\": true,"
                                  "    \"_int\": 1,"
                                  "    \"_double\": 1,"
                                  "    \"_string\": \"bar\","
                                  "    \"_optional\": true"
                                  "  },{"
                                  "    \"_bool\": true,"
                                  "    \"_int\": 2,"
                                  "    \"_double\": 2.0,"
                                  "    \"_string\": \"baz\","
                                  "    \"_optional\": false"
                                  "  }]"
                                  "}")
                              .get<NestedStruct>())
                         .dump(2)
              << std::endl;

    return 0;
}
