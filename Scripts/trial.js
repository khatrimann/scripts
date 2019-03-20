var Nodes = /** @class */ (function () {
    function Nodes(data, next) {
        this.data = data;
        this.next = null;
    }
    return Nodes;
}());
var LinkedListTS = /** @class */ (function () {
    function LinkedListTS() {
        this.head = null;
    }
    LinkedListTS.prototype.insert = function (data) {
        if (!this.head)
            this.head = new Nodes(data, null);
        else {
            var ptr = this.head;
            while (ptr.next != null) {
                ptr = ptr.next;
            }
            ptr.next = new Nodes(data, null);
        }
    };
    return LinkedListTS;
}());
var list = new LinkedListTS();
list.insert(0);
list.insert(1);
list.insert(2);
console.log(list);
