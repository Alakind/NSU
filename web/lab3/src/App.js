import { useState } from "react";
import { InputTextContainer } from "./containers/InputTextContainer";

function App() {

  const [weather, setWeather] = useState({});
  const [places, setPlaces] = useState({});

  return (
    <>
      <h1>
        lab3
      </h1>
      <InputTextContainer setWeather={setWeather} setPlaces={setPlaces} />
      <h3>
        {console.log(weather)}
        {console.log(places)}
      </h3>
    </>
  );
}

export default App;
