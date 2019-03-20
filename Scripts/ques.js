function makePair(a, k) {
    a.sort();
    var pairs = [];
    for (var i = 0; i < a.length - 1; i++)
        if (a[i + 1] - a[i] === k)
            pairs.push([a[i + 1], a[i]]);
    return pairs;
}
var a = [1, 2, 3, 4];
var k = 1;
console.log(makePair(a, k));
