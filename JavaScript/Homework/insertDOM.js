/*
<!-- HTML Sample -->
<ol id="test-list">
    <li class="lang">Scheme</li>
    <li class="lang">JavaScript</li>
    <li class="lang">Python</li>
    <li class="lang">Ruby</li>
    <li class="lang">Haskell</li>
</ol>
*/

'use strict';

let aaa = document.getElementById('test-list');

let bbb = [];
for (let i=0; i<aaa.children.length; i++) {
    bbb.push(aaa.children[i]);
}

bbb.sort(function (s1, s2) {
    let x1 = s1.innerText.toUpperCase();
    let x2 = s2.innerText.toUpperCase();
    if (x1 < x2) {
        return -1;
    }

    if (x1 > x2) {
        return 1;
    }

    return 0;
});

for (let t=0; t<bbb.length; t++) {
    aaa.appendChild(bbb[t]);
}

/*
  Expert's Code:
  
  var ol = document.getElementById('test-list'),lis = [].slice.call(ol.children);
  lis.sort((a,b)=>{return a.innerText.toUpperCase()>b.innerText.toUpperCase()});
  lis.forEach(x=>{ol.appendChild(x)})
*/

// test:
;(function () {
    var
        arr, i,
        t = document.getElementById('test-list');
    if (t && t.children && t.children.length === 5) {
        arr = [];
        for (i=0; i<t.children.length; i++) {
            arr.push(t.children[i].innerText);
        }
        if (arr.toString() === ['Haskell', 'JavaScript', 'Python', 'Ruby', 'Scheme'].toString()) {
            alert('Success!');
        }
        else {
            alert('Failed: ' + arr.toString());
        }
    }
    else {
        alert('Success!');
    }
})();
