# Input Validator (CS 5359 Project)

## Initial Steps

- open terminal
- navigate to project folder
- run "g++ main.cpp"
- run "./a.out"

## File Input

- This program accepts a file with names and phone numbers as **pipe-separated values**.
- Each name/number pair is on its own line.
- Format: name|number

## Terminal Input

- This program accepts one piece of information per line.
- A name and phone number on the same line will be rejected.

## Name

- Maximum of 64 characters per name. The program will ignore any excess characters.
		(DONE) Do this first.
- Accepts alphabetic chars (diacritics allowed), up to two "inner" spaces, up to two commas, up to three apostrophes, and up to three hyphens.
		Use regex kinda like I did for phone number.
- Line terminators or other symbols/ASCII/unicode characters are not allowed.
		(Make regex whitelist in nature.)
- Name must not start with a non-alphabetic character (so no space or other char).
		Use escape char for "alphabetic".

### Example of long name

_Onwuatuegwu Anikulapo-Kuti Alamieyeseigha_ (41 characters, including two spaces). These three words are all common African **surnames**, not first names, but this is an extreme example that will be a little more or even to a __reasonable number__ of chars for a name with realistic first and middle names.

## Phone Number

- Maximum of 32 characters per phone number. The program will ignore any excess characters.
- Accepts numbers, up to one "+" (international dialling prefix), optional parenthesis for area code, characters resembling "extension" (ext, x...), and these other symbols in the following quotes: ".-/"
- Due to the whitelist nature of this regex, line terminators and other symbols/ASCII/unicode characters are not allowed.
- Deny area codes 001, 555 (invalid) and 000 (telemarketer/VoIP).
- Leading spaces are forbidden.