//
// Created by Severin on 25.03.2023.
//

#include "PAMImage/PPM.hpp"

#include <fstream>

namespace pam {
    PPM::PPM(std::size_t width, std::size_t height,
             std::uint16_t maxvalue) : width(width), height(height), maxvalue(maxvalue){

        map.resize(height);

        for (auto& row: map) {
            row.resize(width);
        }
    }

    void PPM::Write(const std::string& filename) {
        std::ofstream file(filename);

        file << "P3" << std::endl;
        file << width << " " << height << std::endl;
        file << maxvalue << std::endl;

        for (auto& row: map) {
            for (auto& elem: row) {
                file << elem[0] << " " << elem[1] << " " << elem[2] << std::endl;
            }
        }
    }

    std::array<std::uint16_t, 3>& PPM::operator()(std::size_t i, std::size_t j) {
        return map[i][j];
    }

    const std::array<std::uint16_t, 3>& PPM::operator()(std::size_t i, std::size_t j) const{
        return map[i][j];
    }
} // pam