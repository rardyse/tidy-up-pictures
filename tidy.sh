#!/bin/bash
# des echo ont été rajouté pour avoir une meilleure visibilité sur le terminal de ce que fait le script à chaque étape
# car à cause de l'écrasement des fichiers (de même date je suppose) dans le dossier all_pictures, on ne voyait pas les fichiers qui étaient copiés et déplacés


mkdir -p all_pictures
mkdir -p sorted_pictures

echo "COPIAGE......"
for folder in "$@"
do
    find "$folder" \( -name "*.jpg" -o -name "*.png" \) -exec cp {} all_pictures/ \;
done

echo "CONTENU DE all_pictures APRES COPIAGE......"
ls -l all_pictures

echo "TRIAGE...."
for file in all_pictures/*
do
    [ -f "$file" ] || continue

    year=$(date -r "$file" +"%Y")
    month=$(date -r "$file" +"%m")
    day=$(date -r "$file" +"%d")
    hour=$(date -r "$file" +"%H")
    minute=$(date -r "$file" +"%M")
    second=$(date -r "$file" +"%S")

    mkdir -p "sorted_pictures/$year/$month"

    ext="${file##*.}"
    name=$(basename "$file" ."$ext")

    newpath="sorted_pictures/$year/$month/${day}-${hour}-${minute}-${second}-${name}.${ext}"
    echo "DEPLACEMENT A: $file -> $newpath"

    mv "$file" "$newpath"
done

echo "LA FIN"
find sorted_pictures -type f