const context = {
    summerAnimes: [
          {
              name: "Re:Zero - Starting Life in Another World",
              src: "https://u.livechart.me/anime/9387/poster_image/d30e2340c85c78a467e60ff4173994c2.jpg?style=small&format=jpg",
              link: "https://www.crunchyroll.com/rezero-starting-life-in-another-world-"
          },
          {
              name: "The God of High School",
              src: "https://u.livechart.me/anime/9808/poster_image/e30946cc663db3b086045c1ad7a08e6a.jpg?style=small&format=jpg",
              link: "https://www.crunchyroll.com/the-god-of-high-school"
          },
          {
              name: "The Misfit of Demon King Academy",
              src:"https://u.livechart.me/anime/9627/poster_image/7a5082cd751807a0e58456d84c6ec132.jpg?style=small&format=jpg",
              link: "https://www.crunchyroll.com/the-misfit-of-demon-king-academy"
          },
          {
              name: "Sword Art Online: Alicization",
              src: "https://u.livechart.me/anime/9733/poster_image/9b0def91b953011ca6e9bc9515a279d4.jpg?style=small&format=jpg",
              link: "https://www.crunchyroll.com/sword-art-online"
          },
          {
              name: "Great Pretender",
              src: "https://u.livechart.me/anime/9502/poster_image/4721a45efd212d8597b3844beff77080.png?style=small&format=jpg",
              link: "https://www.netflix.com/title/81220435"
          },
  
      ],
      fallAnimes: [
        {
            name: "Dungeon Ni Deai",
            src: "https://u.livechart.me/anime/9613/poster_image/4e3733c87bfa56425b16de6237fe2711.jpg?style=small&format=jpg",
            link: "https://www.netflix.com/title/80185873"
        },
        {
            name: "Haikyuu!",
            src: "https://u.livechart.me/anime/9693/poster_image/9fc6e8ee6242a62a6dca665fdf0821e2.png?style=small&format=jpg",
            link: "https://www.crunchyroll.com/haikyu"
        },
        {
            name: "The Day I Became a God",
            src: "https://u.livechart.me/anime/9939/poster_image/8eb7f1d26456ca912ee216679bb8f2d1.jpg?style=small&format=jpg",
            link: "https://www.crunchyroll.com/the-day-i-became-a-god"
        },
        {
            name: "Noblesse",
            src: "https://u.livechart.me/anime/9809/poster_image/aeeb0659aace3b2c4b8dc32d97087c29.png?style=small&format=jpg",
            link: "https://www.crunchyroll.com/noblesse"
        },
        {
            name: "The Seven Deadly Sins",
            src: "https://u.livechart.me/anime/9410/poster_image/4c4397bd4fca0f567986aaf05381b111.jpg?style=small&format=jpg",
            link: "https://www.netflix.com/title/80050063"
        },

    ],
    winterAnimes: [
        {
            name: "Darwin's Game",
            src: "https://u.livechart.me/anime/8230/poster_image/d80748a2dc1a1a397607d3f960bc3327.png?style=small&format=jpg",
            link: "https://www.crunchyroll.com/darwins-game"
        },
        {
            name: "In/Spectre",
            src: "https://u.livechart.me/anime/9193/poster_image/bdff94d828fbdaa2c20ac3a03e4872e1.png?style=small&format=jpg",
            link: "https://www.crunchyroll.com/inspectre"
        },
        {
            name: "Somali and the Forest Spirit",
            src: "https://u.livechart.me/anime/9380/poster_image/b799b1ce3304a5e5a4138d97a446a632.png?style=small&format=jpg",
            link: "https://www.crunchyroll.com/tsomali-and-the-forest-spirit"
        },
        {
            name: "Science Fell in Love, So I tried to Prove ir",
            src: "https://u.livechart.me/anime/9186/poster_image/ae8ec5feefa11e135e8e04f952328dec.jpg?style=small&format=jpg",
            link: "https://www.crunchyroll.com/science-fell-in-love-so-i-tried-to-prove-it"
        },
        {
            name: "A Certain Scientific Railgun T",
            src: "https://u.livechart.me/anime/3555/poster_image/a7f61a474b71763ed8be35d41407c611.png?style=small&format=jpg",
            link: "https://www.crunchyroll.com/a-certain-scientific-railgun"
        },

    ],
    springAnimes: [
        {
            name: "Tower of God",
            src: "https://u.livechart.me/anime/9793/poster_image/ca9ac841e5b168da82bec31046bdccec.jpg?style=small&format=jpg",
            link: "https://www.crunchyroll.com/tower-of-god"
        },
        {
            name: "Love is War?",
            src: "https://u.livechart.me/anime/9649/poster_image/0495de646cdeab34bb743db8333ea47e.png?style=small&format=jpg",
            link: "https://www.crunchyroll.com/pt-br/kaguya-sama-love-is-war"
        },
        {
            name: "Food Wars!",
            src: "https://u.livechart.me/anime/9725/poster_image/edf1f76b7eff0060e0899e836cb39e3a.jpg?style=small&format=jpg",
            link: "https://www.crunchyroll.com/food-wars-shokugeki-no-soma"
        },
        {
            name: "My next Life as a Villainess",
            src: "https://u.livechart.me/anime/3563/poster_image/cfab73309244f99663743a222b7d55da.png?style=small&format=jpg",
            link: "https://www.crunchyroll.com/my-next-life-as-a-villainess-all-routes-lead-to-doom"
        },
        {
            name: "The 8th son? Are you kidding me?",
            src: "https://u.livechart.me/anime/8673/poster_image/18c6892b6cba2444a75e72b3af908006.jpg?style=small&format=jpg",
            link: "https://www.crunchyroll.com/the-8th-son-are-you-kidding-me"
        },

    ]
  };

  /* SUMMER*/
const summerSource = document.querySelector('#summerShows').innerHTML;
const summerTemplate = Handlebars.compile(summerSource);
const summerCompiledHtml = summerTemplate(context);
document.querySelector("#summerBlock").innerHTML = summerCompiledHtml;

/*FALL*/
const fallSource = document.querySelector('#fallShows').innerHTML;
const fallTemplate = Handlebars.compile(fallSource);
const fallCompiledHtml = fallTemplate(context);
document.querySelector("#fallBlock").innerHTML = fallCompiledHtml;

/*WINTER*/

const winterSource = document.querySelector('#winterShows').innerHTML;
const winterTemplate = Handlebars.compile(winterSource);
const winterCompiledHtml = winterTemplate(context);
document.querySelector("#winterBlock").innerHTML = winterCompiledHtml;

/*SPRING*/
const springSource = document.querySelector('#springShows').innerHTML;
const springTemplate = Handlebars.compile(springSource);
const springCompiledHtml = springTemplate(context);
document.querySelector("#springBlock").innerHTML = springCompiledHtml;