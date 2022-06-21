#ifndef DYNAMIC_REFLECTION_H_
#define DYNAMIC_REFLECTION_H_

#include <functional>
#include <memory>
#include <string>
#include <vector>

template <typename FieldType>
using ValueConverter = std::function<void(FieldType* field, const std::string& name)>;

template <typename StructType>
class FieldConverterBase {
public:
    virtual ~FieldConverterBase() = default;
    virtual void operator()(StructType* obj) const = 0;
};

template <typename StructType, typename FieldType>
class FieldConverter : public FieldConverterBase<StructType> {
public:
    FieldConverter(const std::string& name, FieldType StructType::*pointer, ValueConverter<FieldType> converter)
            : field_name_(name), field_pointer_(pointer), value_converter_(converter) {}

    void operator()(StructType* obj) const override {
        return value_converter_(&(obj->*field_pointer_), field_name_);
    }

private:
    std::string field_name_;
    FieldType StructType::*field_pointer_;
    ValueConverter<FieldType> value_converter_;
};

template <class StructType>
class StructValueConverter {
public:
    template <typename FieldType>
    void RegisterField(FieldType StructType::*field_pointer, const std::string& field_name,
            ValueConverter<FieldType> value_converter) {
        fields_.push_back(std::make_unique<FieldConverter<StructType, FieldType>>(
                field_name, field_pointer, std::move(value_converter)));
    }

    void operator()(StructType* obj) const {
        for (const auto& field_converter : fields_) {
            (*field_converter)(obj);
        }
    }

private:
    std::vector<std::unique_ptr<FieldConverterBase<StructType>>> fields_;
};

#endif  // DYNAMIC_REFLECTION_H_
