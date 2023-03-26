#include <PAMImage/PPM.hpp>
#include <PAMImage/PGM.hpp>
#include <PAMImage/PAM.hpp>

void testPAM(){
    std::size_t size = 1024;
    pam::PAM pam(size, size, 3, pam::PAM::Max, pam::PAM::TupleType::RGB);

    for (int i = 0; i < 1024; ++i) {
        for (int j = 0; j < 1024; ++j) {
            auto r = double(i) / (size - 1);
            auto g = double(j) / (size - 1);
            auto b = 0.25;

            auto ir = static_cast<std::uint8_t>(pam::PAM::Max * r);
            auto ig = static_cast<std::uint8_t>(pam::PAM::Max * g);
            auto ib = static_cast<std::uint8_t>(pam::PAM::Max * b);

            pam(i, j) = {ir, ig, ib};
        }
    }

    pam.WriteBinary("tests/out.pam");
}

void testPPM(){
    std::size_t size = 1024;
    pam::PPM ppm(size, size, pam::PPM::Max16);

    for (int i = 0; i < 1024; ++i) {
        for (int j = 0; j < 1024; ++j) {
            auto r = double(i) / (size - 1);
            auto g = double(j) / (size - 1);
            auto b = 0.25;

            auto ir = static_cast<std::uint16_t>(pam::PPM::Max16 * r);
            auto ig = static_cast<std::uint16_t>(pam::PPM::Max16 * g);
            auto ib = static_cast<std::uint16_t>(pam::PPM::Max16 * b);

            ppm(i, j) = {ir, ig, ib};
        }
    }

    ppm.Write("tests/out.ppm");
}

void testPPMBinary(){
    std::size_t size = 1024;
    pam::PPM ppm(size, size, pam::PPM::Max8);

    for (int i = 0; i < 1024; ++i) {
        for (int j = 0; j < 1024; ++j) {
            auto r = double(i) / (size - 1);
            auto g = double(j) / (size - 1);
            auto b = 0.25;

            auto ir = static_cast<std::uint16_t>(pam::PPM::Max8 * r);
            auto ig = static_cast<std::uint16_t>(pam::PPM::Max8 * g);
            auto ib = static_cast<std::uint16_t>(pam::PPM::Max8 * b);

            ppm(i, j) = {ir, ig, ib};
        }
    }

    ppm.WriteBinary("tests/out_binary.ppm");
}

void testPGM(){
    std::size_t size = 1024;
    pam::PGM pgm(size, size, pam::PGM::Max16);

    for (int i = 0; i < 1024; ++i) {
        for (int j = 0; j < 1024; ++j) {
            auto c = double(i) / (size - 1);

            auto ic = static_cast<std::uint16_t>(pam::PGM::Max16 * c);

            pgm(i, j) = ic;
        }
    }

    pgm.Write("tests/out.pgm");
}

void testPGMBinary(){
    std::size_t size = 1024;
    pam::PGM pgm(size, size, pam::PGM::Max8);

    for (int i = 0; i < 1024; ++i) {
        for (int j = 0; j < 1024; ++j) {
            auto c = double(i) / (size - 1);

            auto ic = static_cast<std::uint16_t>(pam::PGM::Max8 * c);

            pgm(i, j) = ic;
        }
    }

    pgm.WriteBinary("tests/out_binary.pgm");
}

int main() {
    testPPM();
    testPPMBinary();
    testPGM();
    testPGMBinary();
    testPAM();

    return 0;
}
