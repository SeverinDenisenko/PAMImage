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

        file.close();
    }

    std::array<std::uint16_t, 3>& PPM::operator()(std::size_t i, std::size_t j) {
        return map[i][j];
    }

    const std::array<std::uint16_t, 3>& PPM::operator()(std::size_t i, std::size_t j) const{
        return map[i][j];
    }

    void PPM::WriteBinary(const std::string& filename) {
        if (maxvalue > Max8)
            throw std::runtime_error("Binary PPM does not have 16 bit extension!");

        std::ofstream file(filename);

        file << "P6" << std::endl;
        file << width << " " << height << std::endl;
        file << maxvalue << std::endl;

        for (auto& row: map) {
            for (auto& elem: row) {
                auto r = static_cast<std::uint8_t>(elem[0]);
                auto g = static_cast<std::uint8_t>(elem[1]);
                auto b = static_cast<std::uint8_t>(elem[2]);
                file.write(reinterpret_cast<char*>(&r), sizeof(std::uint8_t));
                file.write(reinterpret_cast<char*>(&g), sizeof(std::uint8_t));
                file.write(reinterpret_cast<char*>(&b), sizeof(std::uint8_t));
            }
        }

        file.close();
    }
} // pam