import { useState } from "react";
import { InputTextContainer } from "./containers/InputTextContainer";

function App() {

  const [weather, setWeather] = useState({});
  const [places, setPlaces] = useState([]);

  return (
    <>
      <h1>
        lab3
      </h1>
      <InputTextContainer setWeather={setWeather} setPlaces={setPlaces} />
      <h3>
        {(weather !== undefined)
          ?
        <div>{weather.name}</div>
          :
        <div>City</div>}
        {console.log(places)}
      </h3>
    </>
  );
}

export default App;
