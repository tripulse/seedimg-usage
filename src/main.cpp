#include <seedimg.hpp>
#include <seedimg-autodetect.hpp>

#include <seedimg-formats/seedimg-jpeg.hpp>

int main() {
    // this automatically detects the format then calls the appropriate decoder.
    // NOTE that, this CAN throw exceptions (understandable by noexcept mark).
    auto img = seedimg::load("khionu.png");

    // this destination format thru file extension then calls the appropriate
    // encoder with default format specific parameters. you can customize them
    // by calling the actual encoder function (see below).
    seedimg::save("khionu.jpg", img);

    // save the image as a progressive JPEG with 75 quality.
    // encoder can be accessed like this:
    //
    //    seedimg::module::<format>::to(<filename>, <image>, ...)
    //
    // ellipsis (...) mean extra format specific arguments.
    seedimg::modules::jpeg::to("khionu (2).jpg", img, 75, true);
}
