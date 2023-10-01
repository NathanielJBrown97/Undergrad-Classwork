
import { initializeApp } from "https://www.gstatic.com/firebasejs/10.4.0/firebase-app.js";

const firebaseConfig = {
  apiKey: "AIzaSyDw2zaZjgnVzfZpXN3_QU-B5cA7d4-4e6Y",
  authDomain: "a3-profile-app-235f1.firebaseapp.com",
  databaseURL: "https://a3-profile-app-235f1-default-rtdb.firebaseio.com",
  projectId: "a3-profile-app-235f1",
  storageBucket: "a3-profile-app-235f1.appspot.com",
  messagingSenderId: "625571616876",
  appId: "1:625571616876:web:d5d63b41b01af5d6ee2049",
  measurementId: "G-TRBCF6CBN3"
};



const app = initializeApp(firebaseConfig);

import { getDatabase, 
         ref, 
         get, 
         set, 
         child, 
         update, 
         remove 
        } from "https://www.gstatic.com/firebasejs/10.4.0/firebase-database.js";


const db = getDatabase(app); //put app here <--- remove if breaks

var enterID = document.querySelector("#enterID");
var enterName = document.querySelector("#enterName");
var enterAge = document.querySelector("#enterAge");
var findID = document.querySelector("#findID");
var findName = document.querySelector("#findName");
var findAge = document.querySelector("#findAge");


var displayP1Name = document.querySelector("#person1ID");
var displayP1Age = document.querySelector("#person1Age");
var displayP1Hobby = document.querySelector("#person1Hobby");
var displayP1Color = document.querySelector("#person1Color");
var displayP1Food = document.querySelector("#person1Food");
var displayP1Img = document.querySelector("#person1Img");

var displayP2Name = document.querySelector("#person2ID");
var displayP2Age = document.querySelector("#person2Age");
var displayP2Hobby = document.querySelector("#person2Hobby");
var displayP2Color = document.querySelector("#person2Color");
var displayP2Food = document.querySelector("#person2Food");
var displayP2Img = document.querySelector("#person2Img");

function pullDisplays(){
    const dbref = ref(db);

    get(child(dbref, "users/LjuhmO035ihJbogFEpkiTwFUhJj2/"))
    .then((snapshot)=>{
        if(snapshot.exists()){
            displayP1Name.innerHTML = "Name: " + snapshot.val().Name;
            displayP1Age.innerHTML = "Age: " + snapshot.val().Age;
            displayP1Hobby.innerHTML = "Hobby: " + snapshot.val().hobby;
            displayP1Color.innerHTML = "Color: " + snapshot.val().color;
            displayP1Food.innerHTML = "Food: " + snapshot.val().food;
            displayP1Img.src = snapshot.val().image;
        } else {
            alert("No data found");
        }
    })
    .catch((error)=>{
        alert(error)
    })
    // imgId import.src =
}

pullDisplays();

function pullDisplays2(){
    const dbref = ref(db);

    get(child(dbref, "users/fG0kzrpbhfMEOHDxD0PUJ57lKYE2/"))
    .then((snapshot)=>{
        if(snapshot.exists()){
            displayP2Name.innerHTML = "Name: " + snapshot.val().Name;
            displayP2Age.innerHTML = "Age: " + snapshot.val().Age;
            displayP2Hobby.innerHTML = "Hobby: " + snapshot.val().hobby;
            displayP2Color.innerHTML = "Color: " + snapshot.val().color;
            displayP2Food.innerHTML = "Food: " + snapshot.val().food;
            displayP2Img.src = snapshot.val().image;
        } else {
            alert("No data found");
        }
    })
    .catch((error)=>{
        alert(error)
    })
    // imgId import.src =
}

pullDisplays2();

var insertBtn = document.querySelector("#insert");
var updateBtn = document.querySelector("#update");
var removeBtn = document.querySelector("#remove");
var findBtn = document.querySelector("#find");

function InsertData() {
    set(ref(db, "users/"+ enterID.value),{
        Name: enterName.value,
        ID: enterID.value,
        Age: enterAge.value
    })
    .then(()=>{
        alert("Data added successfully");
    })
    .catch((error)=>{
        alert(error);
    });
}

function FindData() {
    const dbref = ref(db);

    get(child(dbref, "users/" + findID.value))
    .then((snapshot)=>{
        if(snapshot.exists()){
            findName.innerHTML = "Name: " + snapshot.val().Name;
            findAge.innerHTML = "Age: " + snapshot.val().Age;
        } else {
            alert("No data found");
        }
    })
    .catch((error)=>{
        alert(error)
    })
    
}

function UpdateData(){
    update(ref(db, "users/"+ enterID.value),{
        Name: enterName.value,
        Age: enterAge.value
    })
    .then(()=>{
        alert("Data updated successfully");
    })
    .catch((error)=>{
        alert(error);
    });
}

function RemoveData(){
    remove(ref(db, "users/"+ enterID.value))
    .then(()=>{
        alert("Data deleted successfully");
    })
    .catch((error)=>{
        alert(error);
    });
}

insertBtn.addEventListener('click', InsertData);
updateBtn.addEventListener('click', UpdateData);
removeBtn.addEventListener('click', RemoveData);
findBtn.addEventListener('click', FindData);