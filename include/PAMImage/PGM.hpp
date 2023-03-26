//
// Created by Severin on 26.03.2023.
//

#ifndef PAMIMAGE_PGM_HPP
#define PAMIMAGE_PGM_HPP

#include <string>
#include <vector>

namespace pam {

    class PGM {
    public:
        static const std::uint16_t Max16 = UINT16_MAX;
        static const std::uint16_t Max8 = UINT8_MAX;

        PGM(std::size_t width, std::size_t height, std::uint16_t maxvalue);
        void Write(const std::string& filename);
        void WriteBinary(const std::string& filename);

        std::uint16_t& operator()(std::size_t i, std::size_t j);
        const std::uint16_t& operator()(std::size_t i, std::size_t j) const;
    private:
        std::size_t width;
        std::size_t height;
        std::uint16_t maxvalue;
        std::vector<std::vector<std::uint16_t>> map;

    };

} // pam

#endif //PAMIMAGE_PGM_HPP
