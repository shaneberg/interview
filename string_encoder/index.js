// given a string of alpha-only characters, encode it to a
// string with each character used followed by it's consecutive count.
// "ssssssjjksss" -> "s6j2k1s3"
// 'aaaapplee' => a4p2l1e2


let encode_string = (input) => {

    // TODO: Consider - is it hacky to reset to 0 here and reset to 1 later on?
    let curCharCount = 0;
    let prevChar = null;
    let encodedString = '';

    for (let i = 0; i < input.length; i++) {
        let curChar = input[i];

        if (prevChar && prevChar !== curChar) {
            encodedString += `${prevChar}${curCharCount}`;
            curCharCount = 1; // Reset character count for next.
        } else {
            curCharCount++;
        }

        prevChar = curChar;
    }

    // TODO: Consider - is it hacky to duplicate this logic outside the loop?
    encodedString += `${prevChar}${curCharCount}`;

    return encodedString;
};

console.log(encode_string('ssssssjjksss'));         // -> "s6j2k1s3"
console.log(encode_string('aaaapplee'));            // -> a4p2l1e2

