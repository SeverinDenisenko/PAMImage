//
// Created by Severin on 26.03.2023.
//

#include "PAMImage/PGM.hpp"

#include <fstream>

namespace pam {
    PGM::PGM(std::size_t width,std::size_t height,
             std::uint16_t maxvalue) : width(width), height(height), maxvalue(maxvalue){
        map.resize(height);

        for (auto& row: map) {
            row.resize(width);
        }
    }

    void PGM::Write(const std::string& filename) {
        std::ofstream file(filename);

        file << "P2" << std::endl;
        file << width << " " << height << std::endl;
        file << maxvalue << std::endl;

        for (auto& row: map) {
            for (auto elem: row) {
                file << elem << " ";
            }
        }
    }

    std::uint16_t& PGM::operator()(std::size_t i, std::size_t j) {
        return map[i][j];
    }

    const std::uint16_t& PGM::operator()(std::size_t i, std::size_t j) const {
        return map[i][j];
    }
} // pam