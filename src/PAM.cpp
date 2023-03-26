//
// Created by Severin on 25.03.2023.
//

#include "PAMImage/PAM.hpp"

#include <fstream>

namespace pam {
    PAM::PAM(std::size_t width, std::size_t height, std::size_t depth, std::uint8_t maxval,
             PAM::TupleType tuple) : width(width), height(height), depth(depth), maxval(maxval), tuple(tuple) {

        map.resize(height);

        for (auto& row: map) {
            row.resize(width);

            for (auto& elem: row) {
                elem.resize(depth);
            }
        }
    }

    void PAM::WriteBinary(const std::string& filename) {
        std::ofstream file(filename);

        file << "P7" << std::endl;
        file << "WIDTH " << width << std::endl;
        file << "HEIGHT " << height << std::endl;
        file << "DEPTH " << depth << std::endl;
        file << "MAXVAL " << maxval << std::endl;

        switch (tuple) {
            case TupleType::BLACKANDWHITE:
                file << "TUPLTYPE BLACKANDWHITE" << std::endl;
                break;
            case TupleType::GRAYSCALE:
                file << "TUPLTYPE GRAYSCALE" << std::endl;
                break;
            case TupleType::RGB:
                file << "TUPLTYPE RGB" << std::endl;
                break;
            case TupleType::GRAYSCALE_ALPHA:
                file << "TUPLTYPE GRAYSCALE_ALPHA" << std::endl;
                break;
            case TupleType::RGB_ALPHA:
                file << "TUPLTYPE RGB_ALPHA" << std::endl;
                break;
        }

        file << "ENDHDR" << std::endl;

        for (auto& row: map) {
            for (auto& elem: row) {
                for (auto val: elem) {
                    file.write(reinterpret_cast<char*>(&val), sizeof(std::uint8_t));
                }
            }
        }

        file.close();
    }

    std::vector<std::uint8_t>& PAM::operator()(std::size_t i, std::size_t j) {
        return map[i][j];
    }

    const std::vector<std::uint8_t>& PAM::operator()(std::size_t i, std::size_t j) const {
        return map[i][j];
    }
} // pam