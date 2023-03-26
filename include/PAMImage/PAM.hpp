//
// Created by Severin on 25.03.2023.
//

#ifndef PAMIMAGE_PAM_HPP
#define PAMIMAGE_PAM_HPP

#include <string>
#include <vector>

namespace pam {

    class PAM {
    public:
        static const std::uint16_t Max16 = UINT16_MAX;
        static const std::uint16_t Max8 = UINT8_MAX;

        enum class TupleType {
            BLACKANDWHITE,
            GRAYSCALE,
            RGB,
            GRAYSCALE_ALPHA,
            RGB_ALPHA,
        };

        PAM(std::size_t width, std::size_t height, std::size_t depth, std::uint16_t maxval, TupleType tuple);
        void WriteBinary(const std::string& filename);

        std::vector<std::uint16_t>& operator()(std::size_t i, std::size_t j);
        const std::vector<std::uint16_t>& operator()(std::size_t i, std::size_t j) const;
    private:
        std::vector<std::vector<std::vector<std::uint16_t>>> map;

        std::size_t width;
        std::size_t height;
        std::size_t depth;
        std::uint16_t maxval;
        TupleType tuple;
    };

} // pam

#endif //PAMIMAGE_PAM_HPP
