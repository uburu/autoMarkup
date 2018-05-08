#ifndef COMMON_NOT_IMPLEMENTED_EXCEPTIONS_HPP
#define COMMON_NOT_IMPLEMENTED_EXCEPTIONS_HPP

#include <exception>
#include <string>
#include <utility>

namespace common {
    /**
     * Исключение для нереализованных методов.
     */
    class NotImplementedException : public std::exception {
    public:
        NotImplementedException() = delete;

        /**
         * Создает экземпляр класса.
         * @param methodName
         * Имя нереализованного метода.
         */
        explicit NotImplementedException(std::string methodName) noexcept :
                methodName(std::move(methodName)) {
        }

        NotImplementedException(const NotImplementedException &exception) noexcept = default;
        NotImplementedException(NotImplementedException &&exception) noexcept = default;

        ~NotImplementedException() noexcept override = default;

        NotImplementedException& operator =(const NotImplementedException &exception) noexcept = default;
        NotImplementedException& operator =(NotImplementedException &&exception) noexcept = default;

        /**
         * Возвращает текстовое представление сообщения об ошибке.
         */
        const char *what() const noexcept override {
            return (std::string("Method \"") + methodName + std::string("\" not implemented yet.")).c_str();
        }

    protected:
        std::string methodName;
    };
}

#endif //COMMON_NOT_IMPLEMENTED_EXCEPTIONS_HPP
