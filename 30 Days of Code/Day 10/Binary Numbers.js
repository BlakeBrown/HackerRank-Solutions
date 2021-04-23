'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

function maxConsecutiveOnes(x) {

    // Initialize result
    let count = 0;

    // Count the number of iterations to
    // reach x = 0.
    while (x != 0) {

        // This operation reduces length
        // of every sequence of 1s by one.
        x = (x & (x << 1));

        count++;
    }
    return count;
}

function main() {
    const n = parseInt(readLine(), 10);
    console.log(maxConsecutiveOnes(n));
}
