(() => {
    'use strict';

    // Runtime analysis: as the size of arr grows, what does this code do?
    let array_search = (arr, target) => {
        let result = -1;

        for (let i = 0; i < arr.length; i++) {
            if (target == arr[i]) {
                result = i;
                break;
            }
        }

        return result;
    };

    let test_array = [1, 20, 23, 45, 50, 55, 62];

    let result = array_search(test_array, 23);
    console.log("Result is: " + result);

    result = array_search(test_array, 46);
    console.log("Result is: " + result);

    let array_binary_search = (arr, target) => {
        // Assume the arr input is sorted.
        let result = -1;

        let curr_max = arr.length - 1;
        let curr_min = 0;

        // TODO: implement while loop

        return result;
    };
})();
