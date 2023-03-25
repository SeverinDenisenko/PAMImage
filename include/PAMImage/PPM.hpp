//
// Created by Severin on 25.03.2023.
//

#ifndef PAMIMAGE_PPM_HPP
#define PAMIMAGE_PPM_HPP

#include <string>
#include <vector>
#include <array>

namespace pam {

    class PPM {
    public:
        static const std::uint16_t Max16 = UINT16_MAX;
        static const std::uint16_t Max8 = UINT8_MAX;

        PPM(std::size_t width, std::size_t height, std::uint16_t maxvalue);
        void Write(const std::string& filename);

        std::array<std::uint16_t, 3>& operator()(std::size_t i, std::size_t j);
        const std::array<std::uint16_t, 3>& operator()(std::size_t i, std::size_t j) const;
    private:
        std::size_t width;
        std::size_t height;
        std::uint16_t maxvalue;
        std::vector<std::vector<std::array<std::uint16_t, 3>>> map;
    };

} // pam

#endif //PAMIMAGE_PPM_HPP
