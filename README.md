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

- Maximum of 64 characters per name. The program will deny the whole string if 65 or more characters are entered at once.
		Do this first.
- Accepts alphabetic chars (diacritics allowed), up to two "inner" spaces, up to two commas, up to three apostrophes, and up to three hyphens.
		In a copy, remove acceptable characters. Reject if a limit is broken.
- Other symbols, ASCII, or unicode characters are not allowed.
		If any other chars left, reject and print error. "The only characters allowed are letters, spaces, commas, apostrophes, and hyphens. Please try again."
- Name must not start with a non-alphabetic character (so no space or other char). However, trailing spaces are allowed, not counted, and will be truncated.
		Reject if first sentence. Truncate spaces if any.

### Example of long name

_Onwuatuegwu Anikulapo-Kuti Alamieyeseigha_ (41 characters, including two spaces). These three words are all common African **surnames**, not first names, but this is an extreme example that will be a little more or even to a __reasonable number__ of chars for a name with realistic first and middle names.

## Phone Number

- Maximum of 32 characters per number. The program will deny the whole string if 33 or more characters are entered at once.
- Accepts Arabic numeric characters, up to one "+", characters resembling "extension" (ext, x...), and up to 5 of a combination of these symbols: ().-/
		Use regex to allow these things.
		Print error based on failure.