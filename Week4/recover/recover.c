#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[512];
    FILE *output = NULL;
    int jpeg_count = 0;
    char filename[8];

    while (fread(buffer, sizeof(BYTE), 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (output != NULL)
            {
                fclose(output);
            }

            sprintf(filename, "%03i.jpg", jpeg_count);
            output = fopen(filename, "w");
            jpeg_count++;
        }

        if (output != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }
    fclose(card);

    return 0;
}

