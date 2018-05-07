#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <exception>
#include <string>
#include <utility>

namespace common
{
    class NotImplementedException : public std::exception {
        public:
            NotImplementedException() = delete;

            explicit NotImplementedException(std::string methodName) noexcept :
                    methodName(std::move(methodName)) {
            }

            NotImplementedException(const NotImplementedException &exception) noexcept = default;
            NotImplementedException(NotImplementedException &&exception) noexcept = default;

            ~NotImplementedException() noexcept override = default;

            NotImplementedException& operator =(const NotImplementedException &exception) noexcept = default;
            NotImplementedException& operator =(NotImplementedException &&exception) noexcept = default;

        const char *what() const noexcept override {
            return (std::string("Method \"") + methodName + std::string("\" not implemented yet.")).c_str();
        }

        protected:
                std::string methodName;
    };
}

#endif //COMMON_TYPES_H
