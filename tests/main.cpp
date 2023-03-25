#include <PAMImage/PPM.hpp>
#include <PAMImage/PGM.hpp>

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

void testPGM(){
    std::size_t size = 1024;
    pam::PGM pgm(size, size, pam::PPM::Max16);

    for (int i = 0; i < 1024; ++i) {
        for (int j = 0; j < 1024; ++j) {
            auto c = double(i) / (size - 1);

            auto ic = static_cast<std::uint16_t>(pam::PPM::Max16 * c);

            pgm(i, j) = ic;
        }
    }

    pgm.Write("tests/out.pgm");
}

int main() {
    testPPM();
    testPGM();

    return 0;
}
