Info<< "Reading physicalProperties\n" << endl;

IOdictionary physicalProperties
(
    IOobject
    (
        "physicalProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

// dimensionedScalar nu
// (
//     "nu",
//     dimViscosity,
//     transportProperties.lookup("nu")
// );
Info<< "Reading diffusionCoef\n" << endl;
dimensionedScalar diffusionCoef
(
    "diffusionCoef",
    dimensionSet(0,2,-1,0,0,0,0), //kg, m, s, K, mol, A, cd
    physicalProperties.lookup("diffusionCoef")
);

Info<< "Reading decayRate\n" << endl;
dimensionedScalar decayRate
(
    "decayRate",
    dimensionSet(0,0,-1,0,0,0,0), //kg, m, s, K, mol, A, cd
    physicalProperties.lookup("decayRate")
);


Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field molarConc\n" << endl;
volScalarField molarConc
(
    IOobject
    (
        "molarConc",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

#include "createPhi.H"

pressureReference pressureReference(p, piso.dict());

mesh.schemes().setFluxRequired(p.name());

autoPtr<viscosityModel> viscosity(viscosityModel::New(mesh));

autoPtr<incompressible::momentumTransportModel> turbulence
(
    incompressible::momentumTransportModel::New(U, phi, viscosity)
);

#include "createMRF.H"
#include "createFvModels.H"
#include "createFvConstraints.H"
