#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char command[4000];
    int i;

    system("mkdir -p all_pictures");
    system("mkdir -p sorted_pictures");

    printf("COPIAGE......\n");
    for (i = 1; i < argc; i++) {
        sprintf(command,
                "find \"%s\" \\( -name \"*.jpg\" -o -name \"*.png\" \\) -exec cp {} all_pictures/ \\;",
                argv[i]);
        system(command);
    }

    printf("CONTENU DE all_pictures APRES COPIAGE......\n");
    system("ls -l all_pictures");

    printf("TRIAGE....\n");
    system(
        "for file in all_pictures/*\n"
        "do\n"
        "    [ -f \"$file\" ] || continue\n"
        "\n"
        "    year=$(date -r \"$file\" +\"%Y\")\n"
        "    month=$(date -r \"$file\" +\"%m\")\n"
        "    day=$(date -r \"$file\" +\"%d\")\n"
        "    hour=$(date -r \"$file\" +\"%H\")\n"
        "    minute=$(date -r \"$file\" +\"%M\")\n"
        "    second=$(date -r \"$file\" +\"%S\")\n"
        "\n"
        "    mkdir -p \"sorted_pictures/$year/$month\"\n"
        "\n"
        "    ext=\"${file##*.}\"\n"
        "    name=$(basename \"$file\" .\"$ext\")\n"
        "\n"
        "    newpath=\"sorted_pictures/$year/$month/${day}-${hour}-${minute}-${second}-${name}.${ext}\"\n"
        "    echo \"DEPLACEMENT A: $file -> $newpath\"\n"
        "\n"
        "    mv \"$file\" \"$newpath\"\n"
        "done"
    );

    printf("LA FIN\n");
    system("find sorted_pictures -type f");

    return 0;
}