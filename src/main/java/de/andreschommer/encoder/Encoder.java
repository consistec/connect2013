package de.andreschommer.encoder;

public class Encoder {

	/**
	 * Encodes the given string
	 * @param string - String to encode
	 * @return the encoded version of the string
	 */
	public String encode(final String string) {
		char[] result = string.toCharArray();
		for (int i = 0; i < result.length; ++i) {
			char letter = result[i];
			if (Character.getType(letter) == Character.LOWERCASE_LETTER) {
				letter = encodeLowercaseLetter(letter);
			} else if (Character.getType(letter) == Character.UPPERCASE_LETTER) {
				letter = encodeUppercaseLetter(letter);
			}

			result[i] = letter;
		}
		return String.valueOf(result);
	}

	/**
	 * Encodes the given uppercase character
	 * @param letter - the character to encode
	 * @return the encoded version of the character
	 */
	private char encodeUppercaseLetter(char letter) {
		if (letter == 'Z')
			letter = 'N';
		else if (letter == 'A')
			letter = 'M';
		else if (letter <= 'M')
			letter -= 1;
		else if (letter >= 'N')
			letter += 1;

		return letter;
	}

	/**
	 * Encodes the given lowercase character
	 * @param letter - the lowercase character to encode
	 * @return the encoded version of the character
	 */
	private char encodeLowercaseLetter(char letter) {
		if (letter < 'l')
			letter += 2;
		else if (letter > 'o')
			letter -= 2;
		else if (letter <= 'm')
			letter -= 11;
		else if (letter >= 'n')
			letter += 11;

		return letter;
	}

}
