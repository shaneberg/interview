const numbers = [34, 12, 89, 5, 73, 31, 64];

console.log(numbers);

// for (let i = 1; i < numbers.length; i++) {
//     let currentElement = numbers[i];
//     let j = i;
//     while(j > 0 && numbers[j - 1] > currentElement) {
//         numbers[j] = numbers[j - 1];
//         j--;
//     }
//     numbers[j] = currentElement;
// }

// console.log(numbers);

const users = [
 { name: 'Alice', age: 25, social: 123466 },
 { name: 'Bob', age: 30, social: 1234 },
 { name: 'Charlie', age: 22, social: 1236 }
];


console.log(users);

// users.sort((user_a, user_b) => {
//     return user_a.age - user_b.age;
// });

for (let i = 1; i < users.length; i++) {
    let currentUser = users[i];
    let j = i;
    while(j > 0 && users[j - 1].age > currentUser.age) {
        users[j] = users[j - 1];
        j--;
    }
    users[j] = currentUser;
}
console.log(users);
