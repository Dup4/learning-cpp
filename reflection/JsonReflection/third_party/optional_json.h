#ifndef OPTIONAL_JSON_H_
#define OPTIONAL_JSON_H_

#include <memory>

// JSON for Modern C++ (see: https://github.com/nlohmann/json)
#include "./json.hpp"

namespace nlohmann {

template <typename T>
struct adl_serializer<std::unique_ptr<T>> {
    static void to_json(json& j, const std::unique_ptr<T>& opt) {
        j = opt ? json(*opt) : json(nullptr);
    }

    static void from_json(const json& j, std::unique_ptr<T>& opt) {
        opt = !j.is_null() ? std::make_unique<T>(j.get<T>()) : nullptr;
    }
};

}  // namespace nlohmann

#endif  // OPTIONAL_JSON_H_
