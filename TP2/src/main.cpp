#include "../include/entry.h"

int main(int argc, char **argv) {
    if(validateEntry(argc, argv))
        readEntry(argc, argv);
}
