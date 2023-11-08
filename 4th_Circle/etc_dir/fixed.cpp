 
// << overloading
{
    int raw = fixed.getRawBits();

    std::string output;

    if (raw == (1 << (sizeof(int) * 8 - 1)))
        output += std::to_string(-(1 << 23));
    else if (raw < 0)
    {
        output = "-";
        raw *= -1;
    }
    else
    {

        return (os);
    }

        raw *= -1;
    }
    std::cout << std::to_string(raw & ((1 << 24) - (1 << 8)));
    if (raw & ((1 << 8) - 1))
    {
        std::cout << ".";

    }
}
