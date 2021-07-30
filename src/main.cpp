#pragma once
#include "Controller.h"

int main()
{
    try
    {
        Controller cont = Controller();
        cont.Run();
    }
    catch (std::exception& e)
    {
        ofstream outfile;
        outfile.open("log.txt");
        outfile << e.what();
        return EXIT_FAILURE;
    }
    catch (...)
    {
        ofstream outfile;
        outfile.open("log.txt");
        outfile << "Unknown exception\n";
        return EXIT_FAILURE;
    }
}
