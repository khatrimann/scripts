var LinkedList = function() {
    this.head = null;
}

var Node = function(data, next) {
    this.data = data;
    this.next = null;
};

LinkedList.prototype.insert = function(data) {
    if(!this.head) this.head = new Node(data, null)
    else {
        var ptr = this.head;
        while(ptr.next!=null){
            ptr=ptr.next;
        }
        ptr.next=new Node(data, null)
    }
};

var list = new LinkedList();
for(let i=0;i<10;i++)
    list.insert(i);
console.log(list);