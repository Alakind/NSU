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
      <h3>
        {weather.xid}
      </h3>
      <InputTextContainer setWeather={setWeather} setPlaces={setPlaces} />
    </>
  );
}

export default App;
