FROM mcr.microsoft.com/dotnet/runtime:6.0 AS base
WORKDIR /app

FROM mcr.microsoft.com/dotnet/sdk:6.0 AS build
WORKDIR /src
COPY ["PrincessDB/PrincessDB.csproj", "PrincessDB/"]
RUN dotnet restore "PrincessDB/PrincessDB.csproj"
COPY . .
WORKDIR "/src/PrincessDB"
RUN dotnet build "PrincessDB.csproj" -c Release -o /app/build

FROM build AS publish
RUN dotnet publish "PrincessDB.csproj" -c Release -o /app/publish

FROM base AS final
WORKDIR /app
COPY --from=publish /app/publish .
ENTRYPOINT ["dotnet", "PrincessDB.dll"]
