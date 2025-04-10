let message = document.getElementById("message");
let next = document.getElementById("next");
// document.body.style.backgroundRepeat = "no-repeat";
// document.body.style.backgroundSize = "cover";

// message.textContent = "Press b to begin";
// let step = 0;

function event1() {
  // if (step === 0 && event.key === "b") {
  document.body.style.backgroundImage = `url(images/welcome.jpg)`;
  audio = document.createElement("audio");
  audiosrc = document.createElement("source");
  audiosrc.src = "images/Aizen.mp3";
  audio.appendChild(audiosrc);
  audio.autoplay = true;
  audio.volume = 0.45;
  document.body.appendChild(audio);
  // audio.controls = true;
  async function text() {
    message.innerHTML = "Yokoso Watashi no Website ye";
    await new Promise((resolve) => setTimeout(resolve, 4000));
    // message.textContent = "Press n";
    message.innerHTML = "";
    message.appendChild(next);
  }
  text();
}

function event2() {
  document.body.style.backgroundImage = `url(images/narutoSasuke.png)`;
  // document.body.style.backgroundPosition = "center";
  // console.log(event.key);
  // step = 2;
  // message.textContent = "press t";
}
events = [event1, event2];
events.forEach((event) => next.addEventListener("click", event));
// next.addEventListener("click", (event) => {
//   step = 1;
//   // } else if (step === 1 && event.key === "n") {
//   //
//   // } else if (step === 2 && event.key === "t") {
//   //   document.body.style.backgroundImage = `url(images/Thorfin.png)`;
//   //   step = 3;
//   //   message.textContent = "press l";
//   // } else if (step === 3 && event.key === "l") {
//   //   document.body.style.backgroundImage = `url(images/luffy.jpeg)`;
//   //   step = 4;
//   //   message.textContent = "press g";
//   // } else if (step === 4 && event.key === "g") {
//   //   document.body.style.backgroundImage = `url(images/garp.png)`;
//   //   step = 5;
//   //   message.textContent = "press b";
//   // } else if (step === 5 && event.key === "b") {
//   //   document.body.style.backgroundImage = `url(images/bb.png)`;
//   //   step = 6;
//   //   message.textContent = "press v";
//   // } else if (step === 6 && event.key === "v") {
//   //   message.textContent = "";
//   //   document.body.style.backgroundImage = `url(images/hbd.jpeg)`;
//   //   video = document.createElement("video");
//   //   video.controls = true;
//   //   video.height = "500";
//   //   video.loop = true;
//   //   video.autoplay = true;
//   //   // video.muted = true;
//   //   video.volume = 0.45;
//   //   // video.parent.height = "250px";
//   //   videosrc = document.createElement("source");
//   //   videosrc.src = "images/bdayvideo.mp4";
//   //   video.append(videosrc);
//   //   message.append(video);
//   //   // message.textContent += "Happy Birthday Dheeraj"
//   //   // document.body.innerHTML = "<video controls><source src="images/bdayvideo.mp4"></video>";
//   //   sorry = document.createElement("div");
//   //   sorry.textContent = "Sorry bro, i didnt have your picture";
//   //   sorry.id = "message";
//   //   sorry.style.top = "85vh";

//   //   container.insertBefore(sorry, message.nextSibling);
//   // }
// });
