# Vocabulary-Practice
This is a Windows application to learn / practice word. It's aimed to be used by especially language learners.

## Requirements
The first thing you need is a .txt file that contains the words you want to practice. This file has to satisfy some conditions for a use without any issues:
1) The first and the second halves (you can think of this as word - meaning pair) have to be separated with the same symbol throughout the whole file. (This symbol will be referred to as "divider" for the rest of the text.)
2) Every line should contain only one pair.

While they are not requirements, there are several points to keep in mind:
1) To add lines that are not actually a part of the word you can use ^ symbol at the beginning of the line. These lines and empty lines won't be read while you select the words to be asked.
2) You should choose a divider that is not a part of a word. If there are two dividers in the same line only the first one will be considered, and the second will be treated as a part of the second half.

See the [example](https://github.com/C-EkoEko/Vocabulary-Practice/releases/download/0.1.0/Example_German-Turkish_UTF16_BE.txt) in the [Releases](https://github.com/C-EkoEko/Vocabulary-Practice/releases).

## How to Use
1) Open the .exe file you downloaded from the [Releases](https://github.com/C-EkoEko/Vocabulary-Practice/releases).
2) Click **Select File**
3) Choose your .txt file that contains words
4) Choose the words to be asked (Remember if there is a line you dont want to select between to lines you want to select, you can just hold CTRL and click them separately)
5) Adjust your settings (See [Settings](https://github.com/C-EkoEko/Vocabulary-Practice/edit/master/README.md#settings))
6) Click **Start Asking**
7) Think the meaning of the word appeared on the new window (yeah, just think)
8) Click **Next** to see the meaning and jump to the next word

## Settings
* **Divider:** As mentioned before this what separates first and second halves of the line. This character is **=** by default. For the [example](https://github.com/C-EkoEko/Vocabulary-Practice/releases/download/0.1.0/Example_German-Turkish_UTF16_BE.txt) it has to be changed to **%**
* **Shuffle:** If this is checked choosen lines will be asked in a random order rather than following the order they are written in the file
* **Reverse:** This will reverse the first and second halves of all lines
* **Randomize Reverse:** This will reverse the halves of some random lines

## To-Do
1) Add images
2) Add **Other Features** part
