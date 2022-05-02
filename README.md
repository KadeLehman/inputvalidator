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

- Between 2 and 41 characters per name. The program will reject the name otherwise.
- Leading spaces are forbidden.
- Accepts alphabetic characters, up to two "inner" spaces, up to two commas, up to three apostrophes, and up to three hyphens.
- Due to the whitelist nature of this regex, line terminators or other symbols/ASCII/unicode characters (including periods) are not allowed.
		
### Example of short name

_Vu_ is a real name with two characters. Any shorter is unreasonable.

### Example of long name

_Onwuatuegwu Anikulapo-Kuti Alamieyeseigha_ (41 characters, including two spaces). These three words are all common African **surnames**, not first names, but this is an extreme example that will be a little longer than a __reasonable number__ of chars for a name with a realistic first, middle, and last name.

## Phone Number

- Maximum of 22 characters per phone number. The program will reject the number otherwise.
- Leading spaces are forbidden.
- Accepts numbers, up to one "+" (international dialling prefix), optional parenthesis for area code, characters resembling "extension" (ext, x...), and these other symbols in the following quotes: ".-/ "
- Due to the whitelist nature of this regex, line terminators and other symbols/ASCII/unicode characters are not allowed.
- Deny area codes 001, 555 (invalid) and 000 (telemarketer/VoIP). Deny country codes with only zeroes (invalid).