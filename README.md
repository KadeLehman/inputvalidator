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
- Leading and trailing spaces are forbidden.
- Accepts alphabetic characters, up to two commas, and up to four each of "inner" spaces, apostrophes, and hyphens.
- Due to the whitelist nature of this regex, line terminators or other symbols/ASCII/unicode characters (including periods) are not allowed.

### Example of short name

_Vu_ is a real name with two characters. Any shorter is unreasonable.

### Example of long name

_Onwuatuegwu Anikulapo-Kuti Alamieyeseigha_ (41 characters, including two spaces). These three words are all common African **surnames**, not first names, but this is an extreme example that will be a little longer than a __reasonable number__ of chars for a name with a realistic first, middle, and last name.

### Valid names

- Ben Franklin
- Vu
- MICHAEL
- Ronald McDonald
- O'Neal, Smith
- Smith O'Neal
- John
- John-Doe, Smith
- Smith, John M
- Smith, John Michael
- Smith, John, M
- Smith, John, Michael
- Onwuatuegwu Anikulapo-Kuti Alamieyeseigha

### Invalid names

- Onwuatuegwuinteresting Anikulapo-Kuti Alamieyekhansecurity
- _Leading Space
- Trailing Spaces__
- TooMuch__InnerSpacing
- John-Mark-Luke-Ben Sean-Connor-Jacob-Riley-Franklin
- Luke "Warm" Water
- Mr. Refrigerator, Period.
- AE12-beta
- 234-234-2345
- Lapsus$
- ,,,epic
- a

### Assumptions

I assume that the user will enter the name as they intend. If they make a mistake and the name is accepted, then the user can simply view the database to check their typo or undesired name.

### Strengths

As shown above, my name-regex accounts for several name formats, and it can detect dubious inputs easily.

### Drawbacks

I had less time to polish the name regex since I created the phone number regex first, and that one is much more robust. So...
- Alphabetic characters only include "A through Z" case-insensitive. No diacritics such as the squiggly n in "jalepeno" and accent marks on vowels are allowed.
- I have not tested many more possible inputs and my logic is not as clean and all-encompassing as my phone number regex logic. You may encounter some unexpected accepts and rejects since my name-regex is rather generalized to make my test cases work.
- Due to this generality, "Smith, John, Michael" is valid even though it is a confusing, ambiguous grouping of the parts of this person's name. It is intended as Last, First, Middle, but this is not immediately obvious.
- I noticed after I made my regex that the project instructions specify that a full name should be supplied. My regex will accept single names, which is not following this instruction, so ideally this would need to be changed before putting the code into production (so people cannot lazily type a first name, then others cannot supply that duplicate name).

## Phone Number

- Maximum of 22 characters per phone number. The program will reject the number otherwise.
- Leading spaces are forbidden.
- Accepts numbers, up to one "+" (international dialling prefix), optional parenthesis for area code, characters resembling "extension" (ext, x...), and these other symbols in the following quotes: ".-/ "
- Due to the whitelist nature of this regex, line terminators and other symbols/ASCII/unicode characters are not allowed.
- Deny area codes 001, 555 (invalid) and 000 (telemarketer/VoIP). Deny country codes with only zeroes (invalid).

### Valid Phone Numbers

- 678-987-0933 xt4811
- +13 (31) 345-3456
- +13(31) 345-3456
- +13 (31)345-3456
- +13(31)345-3456
- +13 31 345-3456
- 987-098-0987
- 34 987 345 654
- +254 65.2345.6547
- (251)654 2345
- 1-724-123-1234

### Invalid Phone Numbers

- +0 123-45-67-89
- (001)123-1234
- 555-444-3333
- 1 555 947 0369
- 1-800-123-1234
- 345-345-3455...
- home:+254.65.54.43
- Benjamin Franklin
- +545 346 765 234 654 3456 345 4567 2345
- 347589347573495783495743543538457458959

### Assumptions

- I assume that a user with honest intentions will enter the phone number as they intend. If they make a mistake and the number is accepted, then the user can simply view the database to check their typo or undesired phone number.
- I also assume these: a user with dishonest intentions will enter a valid phone number that is not theirs, or they will attempt to supply invalid data to exploit the code.

### Strengths

As shown above, my num-regex is quite flexible by accounting for U.S. and international phone number formats without allowing blatently dubious inputs. Also, it rejects false area codes that may be popular on television, but these are not in personal phone numbers.

### Drawbacks

When adding entries to the database, a dishonest user can enter valid phone numbers that are not owned by the corresponding names. Even though I cover a good amount of ground to reject invalid phone numbers, there are still some improvements to this that should be implemented.
1. Many invalid U.S. area codes for each "hundred" have not been checked for within the regex.
2. The user may not enter leading zeroes for the area code or country calling code, even though +001 is valid for the United States of America. This is due to keeping my regex on the simpler side and to reject 002-099 area codes (which also might be valid in countries other than the USA).