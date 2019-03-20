class Nodes {
    public data;
    public next;
    constructor(data, next) {
        this.data = data;
        this.next = null;
    }
}

class LinkedListTS {
    public head;

    constructor(){
        this.head = null;
    }

    insert(data):void {
        if(!this.head) this.head = new Nodes(data, null)
        else {
            var ptr = this.head;
            while(ptr.next!=null){
                ptr=ptr.next;
            }
            ptr.next=new Nodes(data, null)
        }
    }
}

let list = new LinkedListTS();
list.insert(0);
list.insert(1);
list.insert(2);
console.log(list);